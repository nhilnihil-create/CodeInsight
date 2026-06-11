#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> t(N+1),x(N+1),y(N+1);
    t.at(0) = x.at(0) = y.at(0) = 0;
    for(int i=1; i<=N; i++){
        cin >> t.at(i) >> x.at(i) >> y.at(i) ;
    }

    bool can = true;
    for(int i=1; i<=N; i++){
        int dt = t.at(i)-t.at(i-1);
        int dist = abs(x.at(i) - x.at(i-1)) + abs(y.at(i) - y.at(i-1));
        if(dt < dist) {
            can = false;
            break;
        }
        if(dist%2 != dt%2){
            can = false;
            break;
        }
    }
    if(can) cout << "Yes" << endl;
    else    cout << "No" << endl;
    
    
}