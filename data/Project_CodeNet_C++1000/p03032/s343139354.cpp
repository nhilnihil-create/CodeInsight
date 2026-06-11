#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,k;
    cin >> n >> k;
    int r = min(n,k);
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans = -1001001001;
    for(int a=0;a<=r;a++){
        for(int b=0;b<=r-a;b++){
            vector<int> pos;

            for(int i=0;i<a;i++) pos.push_back(v[i]);
            for(int i=0;i<b;i++) pos.push_back(v[n-1-i]);
            sort(pos.begin(),pos.end());

            int away = k-(a+b);
            int sub = 0;
            for(int i=0;i<pos.size();i++){
                if(away>0 && pos[i]<0){
                    away--;
                    continue;
                }
                sub += pos[i];
            }
            ans = max(ans,sub);
            //cout << "a,b = " << a << "," << b << " sub: " << sub << endl;
        }
    }
    cout << ans << endl;
    return 0;
}