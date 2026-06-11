#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    //int A,B,C,D,E;
    //cin >> A >> B >> C >> D >> E;
    
    vector<int> cook_time(5);
    vector<int> ret_cook_time(5);
    rep(i,5){
        cin >> cook_time[i];
    }
    
    int total;
    int min_time = 130*5;
    rep(i,5){
        total=0;
        ret_cook_time = cook_time;
        for(int j=0; j<5; j++){
            if(i !=j ){
                if(ret_cook_time[j] % 10 != 0){
                    ret_cook_time[j] = (ret_cook_time[j]/10)*10 + 10;
                }
            }
            total += ret_cook_time[j];
        }
        
        min_time = min(min_time, total);
    }
    cout << min_time << endl;
}
