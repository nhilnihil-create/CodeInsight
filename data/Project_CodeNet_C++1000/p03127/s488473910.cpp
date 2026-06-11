#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    int n;
    cin >> n;
    vector <long> hp(n);
    rep(i,n) cin >> hp[i];

    sort(all(hp));

    bool ok=true;

    while(ok){
        sort(all(hp));
        while(hp[0]==0){
            hp.erase(hp.begin(),hp.begin()+1);
        }
        if(hp.size()==1) ok=false;
        else{
            for(int i=1; i<hp.size(); i++){
                hp[i] = hp[i] % hp[0];
            }
        }
    }

    cout << hp[0] << endl;
}