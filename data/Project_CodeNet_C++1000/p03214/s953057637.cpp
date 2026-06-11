#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<string>

using namespace std;
const int INF = 1<<30;
typedef long long int ll;

int main(){
	int n;cin>>n;
	int sum=0;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	double min_diff=100000.0, index;
	for(int i=0;i<n;i++){
		double diff=double(sum)/double(n)-double(a[i]);
        if(diff<0)diff*=-1.0;
		if(min_diff>diff){min_diff=diff;index=i;}
	}
	cout << index << endl;
}
