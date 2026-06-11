#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
 
#include <memory.h>
#include <assert.h>
 
#define y0 sdkfaslhagaklsldk
 
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define hash asdgasdgasdgdfrywewery
 
#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512
 
#define ldouble long double
using namespace std;
 
#define bs 1000000007
 
const int N = 600031;
 
int n;
int ans;
 
int cnt[1000];
 
bool is_good(long long val){
	for (int i=0;i<10;i++){
		cnt[i]=0;
	}
	while (val){
		cnt[val%10]++;
		val/=10;
	}
	return (cnt[3]>0&&cnt[5]>0&&cnt[7]>0);
}
 
void backtrack(long long val){
	if (val>n)
		return;
	if (is_good(val))
		++ans;
	backtrack(val*10+3);
	backtrack(val*10+5);
	backtrack(val*10+7);
}
 
int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
 
	cin>>n;
	backtrack(0);
 
	cout<<ans<<endl;
 
//	cin.get(); cin.get();
	return 0;
}