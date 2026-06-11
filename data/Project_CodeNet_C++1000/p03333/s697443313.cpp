#include<cstdio>
#include<iostream>
#include<algorithm>
#define inf 200010
using namespace std;
#define ran 100010
#define i64 long long int
int n,L[ran],R[ran];
i64 sumL[ran],sumR[ran];
i64 calc_lef(int lef,int rig){
	if(lef > rig)
		lef = rig+1;
	else
	if(lef < rig)
		rig = lef;

	if(lef == rig+1){
		return sumL[rig] * 2 - sumR[lef] * 2;
	}
	if(lef == rig){
		if(lef == 0 && rig == 0)
			return 0;
		return sumL[rig] * 2 - L[n-rig+1] - sumR[lef] * 2 + labs(L[n-rig+1]);
	}
}
i64 calc_rig(int lef,int rig){
	if(lef > rig)
		lef = rig;
	else
	if(lef < rig)
		rig = lef + 1;
	if(rig == lef+1){
		return sumL[rig] * 2 - sumR[lef] * 2;
	}
	if(lef == rig){
		if(lef == 0 && rig == 0)
			return 0;
		return sumL[rig] * 2 - sumR[lef] * 2 + labs(R[lef]) + R[lef];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&L[i],&R[i]);
		L[i] = L[i] * 2;
		R[i] = R[i] * 2;
	}
	sort(L+1,L+n+1);
	sort(R+1,R+n+1);
	for(int i=1; i<=n; i++)
		sumR[i] = sumR[i-1] + R[i];
	for(int i=n,t=0; i>=1; i--,t++)
		sumL[t+1] = sumL[t] + L[i];
	long long int res = 0;
	for(int mid=-inf; mid<=inf; mid++){
		int cnt_lef = lower_bound(R+1,R+n+1,mid)-R-1;
		int cnt_rig = n+1-(upper_bound(L+1,L+n+1,mid)-L);
		if(mid <= 0)
		res = max(res, calc_lef(cnt_lef, cnt_rig));
		if(mid >= 0)
		res = max(res, calc_rig(cnt_lef, cnt_rig));
	}
	cout << res / 2 << endl;
	return 0;
}
