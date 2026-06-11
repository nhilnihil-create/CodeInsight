#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;

int main() { 
     int N,A,B;
     cin >> N >> A >> B;
     int ans = B-A;
     if(ans%2==0){
          cout << "Alice";
     }else{
          cout<<"Borys";
     }
	return 0;
}
