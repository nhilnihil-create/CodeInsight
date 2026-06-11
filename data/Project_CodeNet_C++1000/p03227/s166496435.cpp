#include <bits/stdc++.h>
#include <cstdlib>  // abs() for integer 絶対値求めやつ
#include <cmath>    // abs() for float, and fabs()
#include <algorithm>
#include <vector>
#include <string>
#include<iomanip>//浮動小数点数を出力する制度の指定
//使い方　数値をnumとして　cout<<setprecision(n)<<num ;nは桁数
#define rep(i,n) for(int i = 0; i < (n);i++)
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
using namespace std;
using ll =long long;
#define INF 2000000000
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
#define che(a,string) cout<<"//"<<string <<"=="<<(a)<<"//" <<endl;
bool IsInt(double a){int b = a/1;if(a==b){return true;}else {return false;}}
/*覚えてないことメaモ
数値型から文字列に変換　to_string(number);これは簡単
文字列から数値型に変換　stoi(number)
文字列からllに変換　stoll(number)*/

//ここから書き始める

int main(){
	string s;
	cin >> s;
	int k = s.size();
	if(k==2){
		cout<<s<<endl;
	}
	else{
		cout<<s.at(2)<<s.at(1)<<s.at(0)<<endl;
	}

}
