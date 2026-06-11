#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

bool brute(int n, vector <int> a){
	for (int el:a){
    	n-=(n%el);
    }
    if (n==2) return true;
    return false;
}

int main(){
	//
    //freopen("input.txt", "r", stdin);
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin>>k;
    vector <int> a(k);
    vector <ll> ans_min(k+1), ans_max(k+1);
    ans_min[k]=(ll)2;
    ans_max[k]=(ll)2;
    for (int i=0; i<k; ++i){
    	cin>>a[i];
    }
    for (int i=k-1; i>=0; --i){
    	ans_min[i] = ((ans_min[i+1]+a[i]-1)/a[i]) * a[i];
    	ans_max[i] = ((ans_max[i+1]/a[i]) * a[i]) + a[i] - 1;
    	if (ans_min[i]>ans_max[i]) {cout<<-1; return 0;}
    }
    cout<<ans_min[0]<<" "<<ans_max[0];
}