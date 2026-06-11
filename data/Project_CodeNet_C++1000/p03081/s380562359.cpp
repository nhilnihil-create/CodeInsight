#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include <string>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;
int main(){
 	int n,q; cin >>n>>q;
 	string s; cin >>s;
 	char t[q],d[q];
 	for(int i=0;i<q;i++){
 		cin >>t[i]>>d[i];
 	}
 	int ans=n;
 	int low=-1; int high=n;
 	while(low+1<high){
 		int mid=(low+high)/2;
 		int now=mid;
 		for(int i=0;i<q&&0<=now&&now<n;i++){
 			if(t[i]==s[now]){
 				if(d[i]=='L'){
 					now--;
 				}
 				else now++;
 			}
 		}
 		if(now<0){
 			low=mid;
 		}
 		else{
 			high=mid;
 		}
 	}
 	ans-=(low+1);
 	low=-1; high=n;
 	while(low+1<high){
 		int mid=(low+high)/2;
 		int now=mid;
 		for(int i=0;i<q&&0<=now&&now<n;i++){
 			if(t[i]==s[now]){
 				if(d[i]=='L'){
 					now--;
 				}
 				else now++;
 			}
 		}
 		if(now>=n){
 			high=mid;
 		}
 		else{
 			low=mid;
 		}
 	}
 	ans-=(n-high);
 	cout << max(0,ans) << endl;
 }