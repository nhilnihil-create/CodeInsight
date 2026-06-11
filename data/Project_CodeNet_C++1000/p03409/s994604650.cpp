#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
using namespace std;
#define SAY_YES cout<<"YES"<<endl;
#define SAY_Yes cout<<"Yes"<<endl;
#define SAY_NO cout<<"NO"<<endl;
#define SAY_No cout<<"No"<<endl;


const long long int mod=1000000007;
const long long int INF=99999999999999999;


long long int N,used[105]={},res=0;
pair<long long int,long long int>ab[105],cd[105];
int main() {
	cout << fixed << setprecision(18);
	cin>>N;
    for(int i=0;i<N;i++){
        cin>>ab[i].first>>ab[i].second;
    }
    for(int i=0;i<N;i++){
        cin>>cd[i].first>>cd[i].second;
    }
    sort(cd,cd+N);
    for(int i=0;i<N;i++){
        long long int id=-1,maxb=-1;
        for(int j=0;j<N;j++){
            if(used[j]==1){continue;}
            if(ab[j].first<cd[i].first&&ab[j].second<cd[i].second&&maxb<ab[j].second){
                id=j;
                maxb=ab[id].second;
            }
        }
        if(id!=-1){
            res++;
            used[id]=1;
        }
    }
    cout<<res;
} 
