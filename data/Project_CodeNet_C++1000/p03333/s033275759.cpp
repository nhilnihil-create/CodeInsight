/*
for (int i = 0; i < N; ++i){}
 
// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
 
sort(a, a + N, greater<int>());  // a[0:N] を大きい順にソート
 
int num[110] = {0};  // バケット
for (int i = 0; i < N; ++i) {
    num[d[i]]++;  // d[i] が 1 個増える
}
 
map<string, int> mp; // 連想配列 map<キー型, 値型> オブジェクト名
for (int i = 0; i < N; ++i) {
    auto itr = mp.find(s[i]);        // s[i] が設定されているか？
    if(itr != mp.end() ) {
         mp[s[i]] += 1;
    }
    else {
         mp[s[i]] += 1 ;
    }
}
 
 
*/
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
 
using namespace std;

int main() {
	// 入力
    int N;
    cin >> N;
    long long L[N], R[N];
    for (int i = 0; i < N; ++i) cin >> L[i] >>R[i];
 
 
    sort(L, L + N, greater<long long>());  // a[0:N] を大きい順にソート
    sort(R, R + N);  // a[0:N] を大きい順にソート
    int i = 0;
    long long place = 0;
    long long distance = 0;
    long long zero = 0;
    //cout << "=> " << place << " dis " << distance << endl; 
    while (true){
    	if (L[i]<=place && R[i]>=place){
    		distance += abs(zero - place);
    		place = zero;
    		// cout << "=> " << place << " dis1 " << distance << endl; 
    		break;		
    	}
    	else if (L[i]<=place){
    		// distance += 0 - place;
    		// place = 0;
    		// cout << "=> " << place << " dis " << distance << endl; 
    		// break;	
    	} 
    	else{
    		// cout << "L[" << i << "]: " << L[i] << endl;
    		distance += abs(L[i] - place);
    		place = L[i];
    		// cout << "=> " << place << " dis2 " << distance << endl; 
    	}
    	if (R[i]>=place){
    		distance += abs(place);
    		place = zero;
    		// cout << "=> " << place << " dis3 " << distance << endl; 
    		break;	
    	} 
    	else{
    		distance += abs(place - R[i]);
    		place = R[i];
    		// cout << "=> " << place << " dis4 " << distance << endl; 
    	}
    	++i;
    }
     i = 0;
     place = 0;
    long long distance2 = 0;
    
    //cout << "=> " << place << " dis " << distance2 << endl; 
    while (true){
    	if (L[i]<=place && R[i]>=place){
    		distance2 += abs(zero - place);
    		place = zero;
    		// cout << "=> " << place << " dis1 " << distance2 << endl; 
    		break;		
    	}
    	else if (R[i]>=place){
    		distance2 += abs(place);
    		place = zero;
    		// cout << "=> " << place << " dis3 " << distance2 << endl; 
    		break;	
    	} 
    	else{
    		distance2 += abs(place - R[i]);
    		place = R[i];
    		// cout << "=> " << place << " dis4 " << distance2 << endl; 
    	}
    	if (L[i]<=place){
    		// distance += 0 - place;
    		// place = 0;
    		// cout << "=> " << place << " dis " << distance2 << endl; 
    		// break;	
    	} 
    	else{
    		// cout << "L[" << i << "]: " << L[i] << endl;
    		distance2 += abs(L[i] - place);
    		place = L[i];
    		// cout << "=> " << place << " dis2 " << distance2 << endl; 
    	}

    	++i;
    }

	//出力
    cout << max(distance, distance2) << endl;

}
 
 
