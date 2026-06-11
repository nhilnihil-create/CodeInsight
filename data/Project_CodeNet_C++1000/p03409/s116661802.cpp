#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> red(n), blue(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        red[i] = make_pair(a,b);
    }
    for(int i=0; i<n; i++){
        int c, d;
        cin >> c >> d;
        blue[i] = make_pair(c,d);
    }

    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    
    // solve
    int count = 0;
    vector<int> used(n);// red
    for(int i=0; i<n; i++){
        int p = -1, y = -1;
        for(int j=0; j<n; j++){
            if(used[j] == 0 && red[j].first < blue[i].first && red[j].second < blue[i].second){
                if(red[j].second > y){
                    p = j;
                    y = red[j].second;
                }
            }
        }
        if(p != -1){
            count += 1;
            used[p] = 1;
        }
    }
    cout << count << endl;
    return 0;
}