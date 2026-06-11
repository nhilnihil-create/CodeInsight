#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

 
int main() {
  	cin.tie(0); 
  	ios::sync_with_stdio(false);
  	int count = 0;
  	int arr_num = 0;
	int n;
  	cin >> n;
  	vector<unsigned long long> input(n);
  	
  	for(int i = 0; i < n; i++){
    	cin >> input.at(i);
      	
      	if(input.at(i) % 2 == 0){
        	while(input.at(i) % 2 == 0 && input.at(i) > 0){
            	input.at(i) /= 2;
              	count++;
            }
        }
    }
  
  	cout << count << endl;
  	
    return 0;
}