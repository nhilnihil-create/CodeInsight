#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	for(int i=0; i<N; ++i) cin >> a[i];
	for(int i=0; i<N; ++i) cin >> b[i];
	int ans=0;
	for(int d=0; d<29; ++d){
	    vector<int> res(N);
	    int cnt=0;
	    for(int i=0; i<N; ++i){
	        if((a[i])&(1<<d)){
	            cnt += N;
	            cnt %= 2;
	        }
	        res[i]=a[i]%(1<<d);
	    }
	    sort(res.begin(), res.end());
	    for(int i=0; i<N; ++i){
	        if((b[i])&(1<<d)){
	            cnt += N;
	            cnt %= 2;
	        }
	        auto itr=lower_bound(res.begin(), res.end(), (1<<d)-(b[i]%(1<<d)));
	        cnt += res.end()-itr;
	        cnt %= 2;
	    }
	    if(cnt==1) ans |= (1<<d);
	}
	cout << ans << endl;
	return 0;
}
