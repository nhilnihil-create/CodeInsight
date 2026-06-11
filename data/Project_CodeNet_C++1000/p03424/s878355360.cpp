#include <bits/stdc++.h>
using namespace std;

int main() {
			int N;
  cin >> N;
  string colour;
  for(int i = 0; i < N; i++){
    	cin >> colour;
    if(colour == "Y"){cout << "Four" << endl;
                      break;}
	else if(i == N-1 && colour != "Y")
    {cout << "Three" << endl;}
    else if(colour == "P" || colour == "G" || colour == "W")
    				{continue;}}
    }