#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
//#include "D:\C++\test_lib_projects\testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>

bool debug=true;
/*
   Write In New Computer
    By XiaoGeNintendo
	     gwq2017
	Type:
*/

/*
void fo(int id){
	freopen((toString(id)+".txt").c_str(),"w",stdout);
}
*/
string s;
int k;

/*
The biggest answer in [l,r] with k left
*/

int d[305][305][305];
bool f[305][305][305];

int dp(int l,int r,int k){
	//cout<<l<<" "<<r<<" "<<k<<endl;
	int retv;
	if(k<0){
		return 0;
	}else{
		if(f[l][r][k]) return d[l][r][k];
		
		if(l==r){
			retv=1;
		}else{
			if(l>r){
				retv=0;
			}else{
				retv=max(dp(l+1,r,k),dp(l,r-1,k));
				if(k>=1){
					retv=max(retv,dp(l+1,r-1,k-1)+2);
				}
				if(s[l]==s[r]){
					retv=max(retv,dp(l+1,r-1,k)+2);
				}
			}
		}
	}

	f[l][r][k]=true;
	d[l][r][k]=retv;
	return retv;
}

int main(int argc,char* argv[]){
	cin>>s>>k;
	cout<<dp(0,s.size()-1,k);
	return 0;
}
