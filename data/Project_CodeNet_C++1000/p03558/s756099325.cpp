#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
const int INF=1<<29;
/*
Status:Writing
Type:Problemset/HB
Problem ID:Atcoder/ARC/84
Author:XIZCM
*/
int k;
deque<int> dq;
int d[100005];
int main(){
	cin>>k;
	fill(d,d+100005,INF);
	d[1]=1;
	dq.push_front(1);
	while(!dq.empty()){
		int t=dq.front();
		dq.pop_front();
		if(d[(t*10)%k]>d[t]){
			d[(t*10)%k]=d[t];
			dq.push_front((t*10)%k);
		}
		if(d[(t+1)%k]>d[t]+1){
			d[(t+1)%k]=d[t]+1;
			dq.push_back((t+1)%k);
		}
	}
	cout<<d[0]<<endl;
	return 0;
}
