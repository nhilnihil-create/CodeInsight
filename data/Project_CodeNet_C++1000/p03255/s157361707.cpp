
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
    ll i; string s;
    bool exit = false;
    ll N;
    ll X;
    cin >> N >> X;
    vector <ll> x;
    FOR(i,N){
        ll input;
        cin >> input;
        x.push_back(input);
    }
    sort(ALL(x));
    vector <ll> cand;
    ll tryNum,tryNum_,i_;
    ll cost=0;
    ll ret=LLONG_MAX;
    ll xSum[N+1];
    xSum[0] = 0;
    FOR(i, N){
        xSum[i+1] = xSum[i] + x[i];
    }
    FOR(tryNum_, (N+1)/2){
        exit = false;
        tryNum = tryNum_ +  1;
        //cout<<cost<<endl;
        //cout<<tryNum<<endl;
        cost = tryNum*X + N * X;
        if(ret<cost)
            continue;
        //if(tryNum==2)cout<<cost<<endl;
        if( tryNum*2 > N){
            cost += 5 * (xSum[N]-xSum[0]);
            if(ret<cost)
                continue;
            //cand.push_back(cost);
            //continue;
        }else{
            cost += 5 * (xSum[N]-xSum[N-tryNum*2]);
            if(ret<cost)
                continue;
        }
        //if(tryNum==2)cout<<cost<<endl;
        FOR(i_ , (N-tryNum*2 + tryNum-1)/tryNum){
            i = i_ + 1;
            if(tryNum*i > N-tryNum*2){
                cost += (5+i*2) * (xSum[N-tryNum*2 - tryNum*(i-1)] - xSum[0]);
                break;
            }else{
                cost += (5+i*2) * (xSum[N-tryNum*2-tryNum*(i-1)] - xSum[N-tryNum*2-tryNum*i]);
                if(ret<cost){
                    break;
                }
            }
        }
        //cout<<cost<<endl;
        //cand.push_back(cost);
        if(cost < ret)
            ret = cost;
    }
    //sort(ALL(cand));
    //FORR(i, cand)      cout<<i<<endl;
    //cout<<cand[0]<<endl;
    cout<<ret<<endl;
    /*cin>>N;
    vector<ll> V;
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

