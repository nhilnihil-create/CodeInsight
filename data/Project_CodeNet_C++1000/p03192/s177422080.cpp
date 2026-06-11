#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
    cin >> N;
    int a = N/1000;
    int b = (N-a*1000)/100;
    int c = (N-a*1000-b*100)/10;
    int d = N%10;
    int count = 0;
    if(a==2){
      count++;
    }
    if(b==2){
      count++;
    }
    if(c==2){
      count++;
    }
    if(d==2){
      count++;
    }
    cout << count << endl;
}
