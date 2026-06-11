#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int main(){
    int N, M;cin>>N>>M;
    vec_int Pref(M);
    vec_int Y(M);

//    cout<<"a1"<<endl;
    vector<vector<P>> pref_city(N+1);
    rep(i,M){
        cin>>Pref.at(i)>>Y.at(i);
        pref_city.at(Pref.at(i)).push_back(make_pair(Y.at(i),i));
    }

//    cout<<"a2"<<endl;
    vec_int city_ind(M);
    rep(i,N+1){
        sort(pref_city.at(i).begin(),pref_city.at(i).end());
        rep(j, pref_city.at(i).size()){
            int year, city;
            tie(year,city) = pref_city.at(i).at(j);
            city_ind.at(city) = j+1;//city番目の市はP[city]県でj+1番目に生まれた
        }
    }

 //   cout<<"a3"<<endl;
    rep(i,M){
        string pref_str = to_string(Pref.at(i));
        string city_str = to_string(city_ind.at(i));
        while(pref_str.size()<6){
            pref_str = '0'+pref_str;
        }

        while(city_str.size()<6){
            city_str = '0'+city_str;
        }
        cout<<pref_str+city_str<<endl;
    }






    return 0;
}