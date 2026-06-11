#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	string N1,N2;
  cin >> N1 >> N2;
 int n1 = N1.length();
 int n2 = N2.length();
  vector<int> c1(26,0);
  vector<int> c2(26,0);
  froop1(0,n1){
   int a = N1[i] - 'a';
    c1.at(a)++;
  }
  froop1(0,n2){
    int a = N2[i] - 'a';
    c2.at(a)++;
  }
  string s = "",t = "";
  froop1(0,26){
    for(int j = 0;j < c1.at(i);j++){
     s += 'a' + i; 
    }
  }
  froop2(25,-1){
    for(int j = 0;j < c2.at(i);j++){
     t += 'a' + i; 
    }
  }

	froop1(0,min(n1,n2)){
     if(s[i] - t[i] < 0){
       cout << "Yes" << endl;
       return 0;
     }else if(s[i] - t[i] > 0){
       cout << "No" << endl;
       return 0;
     }
    }
  if(n1 < n2){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
return 0;
}