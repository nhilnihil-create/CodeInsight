#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

    /// 11 55
    /// 13 55 kucanje

    map<int,int> cnt;
    int a[200010];
    vector<int> vec;

int main()
{
        ios_base::sync_with_stdio(false);
            cin.tie(NULL);

            int n;
            cin>>n;
            for( int i=0;i<n;i++ ){
                cin>>a[i];
                cnt[ a[i] ]++;
            }
            sort( a,a+n );

            int  step=1;
            while( step <= a[n-1] ){
                vec.pb( step );
                step*=2;
            }
            vec.pb( step );

            int res=0;

            for( int i=n-1;i>=0;i-- ){
                for( int j = 0;j<vec.size();j++ ){
                 //   cout << a[i] << " " << j << " " << vec[j ]<<endl;
                    if( vec[j] > a[i] ){
                     //   cout << a[i] << " " << vec[j] <<endl;
                     if( a[i] != vec[j]-a[i] ){
                        while( cnt[ a[i] ] > 0 && cnt[ vec[j] - a[i] ] > 0 ){
                            cnt[ a[i] ]--;
                            cnt[ vec[j]-a[i] ]--;
                            res++;
                        }
                     }
                     else{
                        while( cnt[ a[i] ] > 1 ){
                            cnt[ a[i] ]-=2;
                            res++;
                        }
                     }
                        break;
                    }
                }
            }

            cout<<res<<endl;

            return 0;
}





























