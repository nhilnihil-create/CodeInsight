#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=s.length();
    int numa=0,numb=0,numc=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            numa++;
        }
        if(s[i]=='b'){
            numb++;
        }
        if(s[i]=='c'){
            numc++;
        }
    }
    int mi=numa,ma=numa;
    mi=min(mi,numb);
    mi=min(mi,numc);
    ma=max(ma,numb);
    ma=max(ma,numc);
    if(ma<=mi+1){
        cout << "YES"<<endl;
    }
    else{
        cout << "NO"<<endl;
    }
    return 0;
}
