#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
set<P> wh;
set<P> bl;

int main(){
    int A, B; cin >> A >> B;
    for(int i=0;i<A-1; i++){
        wh.insert( make_pair(i/50 *2 , i%50 *2) );
    }
    for(int j=0; j<B-1; j++){
        bl.insert( make_pair(99-j/50*2, j%50*2 ) );
    }

    cout <<100 <<" " <<100 << endl;
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            if( wh.count( make_pair(i,j)) ){
            cout << '.';
            }
            else{
                cout << '#';
            }
        }
        cout << endl;
    }
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            if( bl.count( make_pair(i+50,j)) ){
            cout << '#';
            }
            else{
                cout << '.';
            }
        }
        cout << endl;
    }
    
}