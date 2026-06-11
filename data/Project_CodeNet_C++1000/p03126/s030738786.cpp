#include<bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
   	int n,m;
   	cin>>n>>m;
   	map<int,int> table;
   	for(int i = 0; i < n; i++) {
   		int k;
   		cin>>k;
   		for(int j = 0; j < k; j++) {
   			int x;
   			cin>>x;
   			table[x]++;
   		}
   	}

   	int count = 0;
   	for(auto it : table) {
   		if(it.second == n) {
   			count++;
   		}
   	}
   	cout<<count;
	return 0;		
}

