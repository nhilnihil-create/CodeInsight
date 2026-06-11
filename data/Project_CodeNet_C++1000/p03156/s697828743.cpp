#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,a,b,first=0,second=0,third=0,i;
    cin >> n >> a >> b;
    int ar[n];
    for(i=0;i<n;i++) {
    	cin >> ar[i];
    	if(ar[i]<=a) first++;
    	else if(ar[i]>=a+1&&ar[i]<=b) second++;
    	else third++;
    }
    cout << min(first,min(second,third)) << "\n";
    return 0;
}

