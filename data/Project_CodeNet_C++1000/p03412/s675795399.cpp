#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 200001;

int n;
int a[N], b[N];
int aa[N], bb[N];

int main(){
    IOS

   	cin >> n;
   	for(int i = 1; i <= n; i++){
   		cin >> a[i];
   	} 
   	for(int i = 1; i <= n; i++){
   		cin >> b[i];
   	}
   	int val = 0;
   	for(int i = 0; i <= 29; i++){
   		int t = (1<<i);
   		t <<= 1;
   		for(int j = 1; j <= n; j++){
            aa[j] = a[j] % t;
            bb[j] = b[j] % t;
        }
        sort(aa + 1, aa + n + 1);
        sort(bb + 1, bb + n + 1);
        int cnt = 0;
        t >>= 1;
        for(int j = 1; j <= n; j++){
            int p1 = lower_bound(aa + 1, aa + n + 1, t - bb[j]) - aa;
            int p2 = lower_bound(aa + 1, aa + n + 1, 2 * t - bb[j]) - aa;
            int p3 = lower_bound(aa + 1, aa + n + 1, 3 * t - bb[j]) - aa;
            int p4 = lower_bound(aa + 1, aa + n + 1, 4 * t - bb[j]) - aa;
            cnt +=max(0, p2 - p1) + max (0, p4 - p3);
        }
        if(cnt&1)
            val += t;
    }
 	cout << val;

    return 0;
}