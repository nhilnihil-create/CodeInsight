#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define swap(a,b) int tmp=a;a=b;b=tmp

int main(){
 	 int n, alice=0, bob=0, last=0;
 	 cin >> n;
 	 vector<int> data;
 	 rep(i,n){
 	 	int tmp;
 	 	cin >> tmp;
 	 	data.push_back(tmp);
 	 	rep(j,last){
 	 		if(data[last] > data[j]){
 	 			swap(data[last], data[j]);
 	 		}
 	 	}
 	 	last++;
 	 }
 	 rep(i,n){
 	 	alice = (i%2==0) ? alice+data[i]:alice;
 	 	bob = (i%2==1) ? bob+data[i]:bob; 
 	 }
 	 cout << alice - bob;
}