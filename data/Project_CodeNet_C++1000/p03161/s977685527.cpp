    #include <iostream>
    #include <algorithm>
    using namespace std;
    #define mx 200000
    int main(){
        int n, k, mn;
        int h[mx], cost[mx];
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> h[i];
        }
        cost[1] = 0;
        for(int i = 2; i <= n; i++){
             mn = (abs(h[i] - h[i - 1])) + cost[i - 1];
            for(int j = 2; j <= k ; j++){
                if (i - j >= 1){
                    if(mn > ((abs(h[i] - h[i - j]) + cost[i - j]))){
                        mn = abs(h[i] - h[i - j]) + cost[i - j];
                    }
                }
            }
            cost[i] = mn;
        }
        cout << cost[n] << endl;
        return 0;
    }
