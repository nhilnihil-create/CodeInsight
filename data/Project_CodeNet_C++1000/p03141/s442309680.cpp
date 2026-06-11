#include<bits/stdc++.h>
using namespace std;

//typedef
typedef long long LL;
typedef unsigned int UINT;
typedef unsigned long long ULL;
typedef set<int, greater<int> > setdownINT;
typedef set<long long, greater<long long> > setdownLL;
typedef priority_queue<int, vector<int>, greater<int> > priqueupINT;
typedef priority_queue<long long, vector<long long>, greater<long long> > priqueupLL;
//container utill
#define ALL(v) (v).begin(),(v).end()
#define sortdown(v) sort((v).begin(),(v).end()), reverse((v).begin(),(v).end())
#define PB(a) push_back(a)
#define MP make_pair
#define MT make_tuple
//constant
#define PI 3.141592653589793

int main(){
    //input
    LL N;
    cin >> N;
    LL A[N], B[N];
    LL i;
    vector<pair<LL,LL> > vec;
    for(i=0; i<N; i++){
        cin >> A[i] >> B[i];
        vec.PB(MP(A[i]+B[i],i));
    }

    //calc
    sortdown(vec);
    vector<LL> taka, aoki;
    for(i=0; i<N; i++){
        if(i%2==0){
            taka.PB(vec[i].second);
        }else{
            aoki.PB(vec[i].second);
        }
    }
    LL ans=0;
    for(i=0; i<taka.size(); i++){
        ans+=A[taka[i]];
    }
    for(i=0; i<aoki.size(); i++){
        ans-=B[aoki[i]];
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}