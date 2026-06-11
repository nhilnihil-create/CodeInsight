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

int binary_search(vec_int &vec_to_search, int comp_val){
    //これは何をやるかというと、
    //vec_to_searchが昇順にソートされていることが前提
    //vec_to_search[i-1]<=comp_val<vec_to_search[i]となるiを探す

    int N = vec_to_search.size();
    int lb = -1, ub = N;
    while(ub-lb>1){
        int mid = (ub+lb)/2;
        if(vec_to_search[mid]>comp_val){
            ub=mid;
        }else{
            lb=mid;
        }
    }
    return ub;

}

int main(){
    int N;
    cin>>N;
    vector<int> A(N),B(N),C(N);
    rep(i,N){
        cin>>A.at(i);
    }
    rep(i,N){
        cin>>B.at(i);
    }
    rep(i,N){
        cin>>C.at(i);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());


    ll total_combi_N = 0;
    vector<int> A_B(N), B_C(N);
    rep(i,N){
//        A_B.at(i) = binary_search(B, A.at(i));
//        B_C.at(i) = binary_search(C, B.at(i));
//        auto iter1 =(upper_bound(B.begin(),B.end(), A.at(i))); 
        auto iter1 =(lower_bound(A.begin(),A.end(), B.at(i))); 
//        A_B.at(i) = distance(B.begin(),iter1);
        auto iter2 = (upper_bound(C.begin(),C.end(), B.at(i)));
//        B_C.at(i) = distance(C.begin(),iter2);
//        cout << (N-distance(A.begin(),iter1))<<" "<<(N-distance(C.begin(),iter2))<<endl;

        total_combi_N += (distance(A.begin(),iter1))*(N-distance(C.begin(),iter2));
        //cout<<A_B.at(i) << " "<<B_C.at(i)<<endl;
    }

/*
    vector <int> B_count(N,0);
    B_count.at(N-1) = N-B_C.at(N-1);
    rep(i,N-1){
        //A.at(i)を選択したとき、A_B.at(i)以降のBを選択できる
        //ただし、B.at(j)を選択したときに選べるCの数はB_C.at(j)である
        //したがって、sigma_{A_B.at(i)}^{N} B_C.at(j)を計算しないといけない
        //このためにはBをしっぽのほうから足し算したものが必要になる。
        B_count.at(N-2-i) = (N-B_C.at(N-2-i)) + B_count.at(N-1-i);
    }

    ll total_combi_N = 0;
    rep(i,N){
        //A.at(i)を選択したとき、A_B.at(i)以降のBを選択できる
        if(A_B.at(i)==N)continue;
        total_combi_N += B_count.at(A_B.at(i));
    }
//    rep(i,N){
//        cout<<B_count.at(i)<<endl;
//    }

*/
    cout << (total_combi_N)<<endl;

//    int binary_search(B, a)

    return 0;
}