#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main(){
    long n,m;
    cin >> n >> m;

    vector <long> price(n);
    map <long, int> a;// a[値段]=本数
    rep(i,n){
        long c;
        int d;
        cin >> c >> d;

        if(a.count(c)) a.at(c) += d;
        else a[c] = d;
        price[i] = c;
    }

    sort(all(price));
    price.erase( unique (  price.begin() , price.end() ) , price.end() );

    long count=0;
    long sum=0;

    for(long x:price){
        if((count + a.at(x)) >= m){
            sum += x * (m-count);
            break;
        }

        else{
            count += a.at(x);
            sum += x * a.at(x);
        }
    }

    cout << sum << endl;
}
