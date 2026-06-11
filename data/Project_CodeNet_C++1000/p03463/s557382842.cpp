//
//  main.cpp
//  ABC124
//
//  Created by hiroaki on 2019/05/07.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <tuple>
#include <bitset>
#include <string>
#include <sstream>
#include <iomanip>
//pair sort firstに揃う

#define int long long
#define double long double
#define Rap(n,i) for(int (i)=0;(i)<(n);(i)++)
#define Pr(n) cout<<n<<endl;
#define PairV vector<pair<int , int> >
#define F first
#define S second
#define Vector1 vector<int>
#define VectorS vector<string>
#define vector2 vector<vector<int> >
#define index(v,x) find((v).begin(), (v).end(), (x))-(v).begin()
#define ctoi(c) (int)(c-'0')
#define incin(n) int (n); cin>>(n);
#define incin2(n,m) int (n),(m); cin >> (n)>>(m);
#define stcin(s) string (s); cin>>(s);
#define all(v) (v).begin() , (v).end()
namespace Mathf
{
    const int INF = 1000000000000;
    const double PI = 3.14159274;
    const double Rad2Deg = 57.29578;
    const double log2(double a,double b);
    const double log2(double a,double b){
        return log(b)/log(a);
    }
} // namespace Mathf

using namespace std;

int MD(pair<int,int> a,pair<int,int> b){//ManhattanDisRance
    return abs(a.first-b.first) + abs(a.second-b.second);
}
int MOD(int a,int b){
    return abs(a%b);
}
template <typename T1,typename T2> bool Comp (pair<T1,T2> a,pair<T1,T2> b){
    if(a.first!=b.first){
        return a.first<b.first;//first昇順
    }
    if(a.second!=b.second){
        return a.second > b.second;//second降順
    }else{
        return  true;
    }
}
double Dis(pair<int,int> a,pair<int,int> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int Step(int N){
    if(N==0){
        return 1;
    }else{
        return N*Step(N-1);
    }
}
int Pemu(int n,int r){
    int ans = n;
    for(int i=0;i<r;i++){
        ans*=(ans-i);
    }
    return ans;
}
int Comb(int n,int m){
    int ans=n;
    for(int i=0;i<m;m++){
        ans*=(ans-i);
    }
    return ans/Step(m);
}
int Digit(int x){
    string ss = to_string(x);
    int size = ss.size();
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=ctoi(ss[i]);
    }
    return sum;
}
class City{
    public:
        int num;
        int p;
        int n;
        int y;
        int id;
        City();
};
City::City(){
    num = 0;
    p=0;
    n=0;
    y=0;
    id=0;
}

signed  main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // incin2(n,m);
    // vector<City> cities(m+1);
    // Rap(m,i){
    //     cities[i].num = i+1;
    //     cin >> cities.at(i).p >> cities.at(i).y;
    // }
    // sort(cities.begin(),cities.end()-1,[](const City &a,const City &b){
    //     if(a.p==b.p){
    //         return a.y<b.y;
    //     }else{
    //         return a.p<b.p;
    //     }
    // });
    // int log  = 1;
    // Rap(m,i){
    //     cities[i].n = log;
    //     log++;
    //     if(cities[i].p!=cities[i+1].p){
    //         log = 1;
    //     }
    // }
    // sort(cities.begin(),cities.end()-1,[](const City &a,const City &b){return a.num<b.num;});
    // Rap(m,i){
    //     stringstream ss;
    //     ss<<setw(6)<<setfill('0')<<cities[i].p<<setw(6)<<cities[i].n;
    //     cout<<ss.str()<<endl;
    // }
    incin(n);
    incin2(a,b);
    if((b-a)%2==1){
        cout<<"Borys"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
    return 0;
}