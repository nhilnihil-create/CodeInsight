#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

using LL = long long;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

template<typename T>
T vec_min(V<T> v){return *min_element(ALL(v));}

template<typename T>
T vec_max(V<T> v){return *max_element(ALL(v));}

int main(){
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    Vi x(N),y(M);
    REP(i,N) cin>>x[i];
    REP(i,M) cin>>y[i];
    x.pb(X);
    y.pb(Y);

    int x_max = vec_max(x);
    int y_min = vec_min(y);

    if(x_max<y_min){
        cout<<"No War"<<endl;
    }else{
        cout<<"War"<<endl;
    }
    return 0;
}