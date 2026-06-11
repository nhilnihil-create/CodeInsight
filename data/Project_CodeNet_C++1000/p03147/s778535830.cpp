#include <bits/stdc++.h>
using namespace std;
int min_range(int left_ind,int right_ind, vector<int> &v){
	int mini = 101;
	for(int i = left_ind;i<=right_ind;i++){
		mini = min(v[i],mini);
	}
	for(int i = left_ind;i<=right_ind;i++){
		v[i] -= mini;
	}
	return mini;
}
int main(){
	int n,a;
	cin >> n;
	vector<int> h(n);
	for(int i=0;i<n;i++){
		cin >> a;
		h[i]=a;
		//cout << h[i];
	}
	
	int count=0;
	//int k = 0;
	while(true){
		int left=-1,right=-1;
		//for(int i = 0;i<n;i++) cout << i << " " << h[i] << endl;
		
		if(h[0]>0) left = 0;
		for(int i =1;i<n;i++){
			if(h[i]>0 && h[i-1]==0 && left!=0) left = i;
			if(h[i-1]>0 && h[i] ==0) {right = i-1; break;}
		}
		//cout << left << "           " << right << endl;
		if(right == -1) right = n-1;
		int c = min_range(left,right,h);
		count+=c;
		//cout << c << endl;
		//k++;
		if(left == -1) break;
	}
	cout << count;
}
		
		
    
	

