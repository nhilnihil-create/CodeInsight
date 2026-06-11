#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

void quick_sort(long long s[], long long left, long long right){
	long long p, l, r, t;
    l = left, r = right;
    p = s[(l+r)/2];
    while(1){
    	while(s[l] < p)
    		l++;
    	while(s[r] > p)
        	r--;
        if(l >= r) break;
        t = s[r];
        s[r] = s[l];
        s[l] = t;
        l++;r--;
    }
    if(left < l-1)
    	quick_sort(s, left, l-1);
    if(right > r+1)
    	quick_sort(s, r+1, right);
}

int comb(long n, long r){
	if(n == 0) return 1;
    else if(r == 0) return 1;
    else if(r == n) return 1;
    else return comb(n-1, r) + comb(n-1, r-1);
}

int main(){
    long long n, t, l, count = 0;
    cin >> n;
    long long a[n], s[n+2];
    
    for(int i = 0; i < n; i++){
    	cin >> t;
    	a[i] = t;
    }
    
    s[0] = 0;
    for(int i = 1; i < n+1; i++){
    	s[i] = a[i-1] + s[i-1];
    }
    
    //sort(s, s+n+1);
    quick_sort(s, 0, n);

    l = 0;s[n+1] = 1000000000000000LL;
    for(int i = 0; i <= n+1; i++){
    	if(s[i]!=s[l]){
        	count += (i-l)*(i-l-1)/2;
            l = i;
        }
    }
    
    cout << count << endl;
}




