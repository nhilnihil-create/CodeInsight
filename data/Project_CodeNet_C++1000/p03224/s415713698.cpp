
#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


void solve() {
    int i,j,k,l,r,x,y; string s;
    bool exit = false;
    vector <int> cand;
    x=0;
    i=1;
    int N;
    cin>>N;
    while(true){
        x=(i+1)*i/2;
        if(x<=100000){
            cand.push_back(x);
        }else{
            break;
        }
        i++;
    }
    //cout<<cand.size()<<endl; 446
    if(find(ALL(cand),N)==cand.end()){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    k=sqrt(N*2)+1;//N=kC2
    cout<<k<<endl;
    int table[k][k];
    FOR(i,k){
        FOR(j,k){
            table[i][j]=-1;
        }
    }
    int cnt=1;
    FOR(i,k){
        FOR(j,i){
            table[i][j]=cnt;
            table[j][i]=cnt;
            cnt++;
        }
    }
    FOR(i,k){
        string ret="";
        ret += to_string(k-1);
        FOR(j,k){
            if(i==j) continue;
            ret += " ";
            ret += to_string(table[i][j]);
        }
        cout<<ret<<endl;
    }
    /*cin>>N;
    vector<ll> V((N+1)*(N+1));
    FOR(x,N+1) {
            FOR(y,N+1) {
                    ll ret=1;
                    FOR(i,x) ret*=2;
                    FOR(i,y) ret*=5;
                    V.push_back(ret);
            }
    }
    sort(ALL(V));
    FORR(v,V) cout<<v<<endl;*/
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

