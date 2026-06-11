#include <bits/stdc++.h>
using namespace std;

int main(){
 int N;
 cin >> N;
 vector<int> vec;
 for(int i = 1; i <= N; i++){
   if(i % 2 == 1) vec.push_back(i);
 }
 int count = 0, count2 = 0;
 for(int i = 0; i < vec.size(); i++){
   count = 0;
   for(int j = 1; j <= N; j++){
     if(vec.at(i) % j == 0) count++;
   }
   if(count == 8) count2++;
 }
 cout << count2 << endl;
}
