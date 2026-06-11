#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int H,W; cin>>H>>W;
	int h,w; cin>>h>>w;
	cout <<H*W-(h*W+H*w-h*w)<<endl;
}