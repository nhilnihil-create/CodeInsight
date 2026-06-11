#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	cout << 0 << endl;
	fflush(stdout);
	string base="Vacant";
	string o="Male";
	string str; cin >> str;
	if(str==base){
		return 0;
	}
	else{
		int vi=0;
		if(str==o)vi=1;
		int l=1; int r=n;
		while(l<r){
			int mid=(l+r)/2;
			cout << mid << endl;
			fflush(stdout);
			cin >> str;
			if(str==base){
				return 0;
			}
			int mi=0;
			if(str==o)mi=1;
			if(mid%2==1){
				if(mi==vi)r=mid-1;
				else l=mid+1;
			}
			else{
				if(mi==vi)l=mid+1;
				else r=mid-1;
			}
		}
		cout << l << endl;
		fflush(stdout);
		cin >> str;
	}
}