#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int N;
cin >> N;
int num[10000];
int ans = 0;
for(int i = 0; i< N;i++)cin >> num[i],num[i]--,ans+=num[i];
cout << ans << endl;

}
