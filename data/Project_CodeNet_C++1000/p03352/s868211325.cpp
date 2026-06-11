#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    for(int i=x;i>=2;i--){
    	for(int j=2;j*j<=i;j++){
    		int m = i;
    		if(m%j==0){
    			while(m%j==0){
    				m=m/j;
    			}
    			if(m==1){
    				cout<<i<<endl;
    				return 0;
    			}
    			else{
    				continue;
    			}
    		}
    		else{
    			continue;
    		}
    	}
    }

    cout << 1 << endl;

    return 0;
}