#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main() {
int N;
cin >> N;
int slime[100];
for(int i = 0;i<N;i++)cin>>slime[i];
int count = 0;
for(int i = 0;i<N-1;i++){
if(slime[i] == slime[i+1]) count++, i++;
}
cout << count << endl;
}
