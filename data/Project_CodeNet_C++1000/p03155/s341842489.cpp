#include<bits/stdc++.h>


using namespace std;
                                                                    

int main(){
  int n,h,w;
  cin >> n >> h >> w;
  int across = n-w + 1;
  int down = n-h + 1;
  cout << across * down<< endl;
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

}

           	