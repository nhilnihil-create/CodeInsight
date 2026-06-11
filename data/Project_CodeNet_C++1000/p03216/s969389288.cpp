#include <iostream>
#include <string>
#define ll long long
using namespace std;

int d[1000010];
ll m_cnt[1000010], c_num[1000010], mc[1000010];

int main() {
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	int d_now=0;
	for(int i=0; i<N; ++i){
	    if(S[i]=='D'){
	        d[d_now]=i;
	        ++d_now;
	    }
	    m_cnt[i+1]=m_cnt[i];
	    if(S[i]=='M') ++m_cnt[i+1];
	    c_num[i+1]=c_num[i];
	    mc[i+1]=mc[i];
	    if(S[i]=='C'){
	        ++c_num[i+1];
	        mc[i+1] += m_cnt[i];
	    }
	}
	for(int i=0; i<Q; ++i){
	    int k;
	    cin >> k;
	    ll ans=0;
	    for(int i=0; i<d_now; ++i){
	        ans += mc[min(d[i]+k, N)]-mc[d[i]]-(c_num[min(d[i]+k, N)]-c_num[d[i]])*m_cnt[d[i]];
	    }
	    cout << ans << endl;
	}
	return 0;
}
