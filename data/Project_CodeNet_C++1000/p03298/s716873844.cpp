#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

long long ruijou(int n, int k){
    if(k==0) return 1;
    int x=k/2;
    long long t=ruijou(n,x);
    
    if(k%2==1) return n*t*t;
    else return t*t;
}

int main(){
    int N;
    string S;
    cin>>N>>S;
    vector<char> l,r;
    for(int i=0;i<N;i++) {l.push_back(S.at(i)); r.push_back(S.at(2*N-1-i));}
    vector<char> l2=l,r2=r;
    sort(l2.begin(),l2.end());
    sort(r2.begin(),r2.end());
    bool okay=true;
    for(int i=0;i<N;i++) if(l2.at(i)!=r2.at(i)) okay=false;
    ll ans=0;
    //cout<<l.size()<<endl;
    if(okay){
        unordered_map<string,ll> mp;
        for(int bit=0; bit<(1<<N); bit++){
            string R,B;
            for(int i=0;i<N;i++){
                if(bit & (1<<i)) R.push_back(l.at(i));
                else B.push_back(l.at(i));
            }
            
            R+='.';
            R+=B;
            if(!mp[R]) mp[R]=1;
            else mp[R]++;
        }
        /*for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << "key = " << itr->first           // キーを表示
                        << " val = " << itr->second <<endl;    // 値を表示
        }*/

        for(int bit=0; bit<(1<<N); bit++){
            string R,B;
            for(int i=0;i<N;i++){
                if(bit & (1<<i)) R.push_back(r.at(i));
                else B.push_back(r.at(i));
            }
            R+='.';
            R+=B;
            if(mp[R]) ans+=mp[R];
        }

    }

    cout<<ans<<endl;


}