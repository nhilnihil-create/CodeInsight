

#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int chmax(pair<int, vector<int> >& t0, pair<int, vector<int> > t1){
	if(t0.first<t1.first) {
		t0=t1; return 0;
	}else if(t0.first>t1.first) {
		return 0;
	}else{
		for(int i=0; i<(int)t0.second.size(); i++){
			if(t0.second[i]<t1.second[i]) {t0=t1; return 0;}
			if(t0.second[i]>t1.second[i]) return 0;
		}
	}
	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(10,0);
	for(int i=0; i<m; i++){
		int l;
		cin >> l;
		if(l==1 && a[2]<l) a[2]=1;
		if(l==2 && a[5]<l) a[5]=2;
		if(l==3 && a[5]<l) a[5]=3;
		if(l==4 && a[4]<l) a[4]=4;
		if(l==5 && a[5]<l) a[5]=5;
		if(l==6 && a[6]<l) a[6]=6;
		if(l==7 && a[3]<l) a[3]=7;
		if(l==8 && a[7]<l) a[7]=8;
		if(l==9 && a[6]<l) a[6]=9;
	}
	vector<pair<int, int> > ap;

	for(int i=0; i<10; i++){
		if(a[i]!=0) ap.push_back(make_pair(i, a[i]));
	}

	sort(ap.begin(), ap.end(), [](auto lhs, auto rhs){
		return lhs.second > rhs.second;
	});

	//for(int i=0; i<(int)ap.size(); i++) cout << ap[i].first << " " << ap[i].second << endl;

	vector<pair<int, vector<int> > > r(n+1, make_pair(0, vector<int>((int)ap.size(),0)));
	pair<int, vector<int> > t0=make_pair(0, vector<int>((int)ap.size(),0));
	pair<int, vector<int> > t1=make_pair(0, vector<int>((int)ap.size(),0));

	for(int i=0; i<(int)ap.size(); i++){
		if(ap[i].first<n+1){
			r[ap[i].first].first=1;
			r[ap[i].first].second[i]=1;
		}
	}

	//for(int i=0; i<n; i++) cout << r[i].first;
	//cout << endl;

	for(int i=1; i<n+1; i++){
		t0=r[i];
		for(int l=0; l<(int)ap.size(); l++){
			int j;
			j=i-ap[l].first;
			if(j<0) continue;
			t1=r[j];
			if(t1.first==0) continue;
			t1.first++;
			t1.second[l]++;
			chmax(t0, t1);
		}
		r[i]=t0;
	}

	//for(int i=0; i<n; i++) cout << r[i].first;
	//cout << endl;

	vector<int> rmax(10,0);

	for(int l=0; l<(int)ap.size(); l++){
		rmax[ap[l].second]=t0.second[l];
	}

	for(int i=9; 0<=i; i--){
		for(int j=0; j<rmax[i]; j++) cout << i;
	}
	cout << endl;
	return 0;

}

