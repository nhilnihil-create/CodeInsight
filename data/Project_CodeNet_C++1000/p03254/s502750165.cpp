#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,x;
    cin >> N >> x;

    vector<int> a(N);

    for(int i=0;i<N;i++){
        cin >> a.at(i);
    }

    sort(a.begin(),a.end());

    int ans=0;

    for(int i=0;i<N;i++){
        if(x>=a.at(i)&&i<N-1){
            ans++;
            x -= a.at(i);
        }
        else if(i=N-1){
            if(x==a.at(i)){
                ans++;
            }
            else{}
        }
        else if(x<a.at(i)){
            break;
        }
    }

    cout << ans << endl;

}