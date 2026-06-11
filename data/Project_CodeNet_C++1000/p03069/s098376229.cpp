#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;
    
    string s;
    cin>>s;


    //全部黒か、全部白か、前半白で後半黒か、その小さい方
    vector<int> white_cnt(n,0);
    vector<int> black_cnt(n,0);
    int white=0,black=0;
    for(int i=0;i<n;i++){
        if(s.at(i)=='#')
            white++;

        if(s.at(n-1-i)=='.')
            black++;

        white_cnt.at(i)=white;
        black_cnt.at(n-1-i)=black;
    }


    int min_wk=s.size();
    for(int i=0;i<n-1;i++){
        min_wk=min(min_wk,white_cnt.at(i)+black_cnt.at(i+1));
    }

    cout<<min(min_wk,min(black,white))<<endl;

    return 0;
}