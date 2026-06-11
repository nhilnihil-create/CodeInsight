#include <bits/stdc++.h>
using namespace std;



int main() {


int n; cin >> n;
string s; cin >> s;
int red  =0;
int blue = 0;
for(int i = 0; i < n; i++){
  if(s[i] == 'R')red++;
  if(s[i] == 'B') blue++;
}

if(red > blue)
cout <<  "Yes";
else
cout << "No";





}


	
