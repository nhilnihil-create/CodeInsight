#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    //input
    int N;
    cin >> N;
    vector<pair<int,int> > red;
    vector<pair<int,int> > blue;
    int i,j;
    int rx,ry,bx,by;
    for(i=0; i<N; i++){
        cin >> rx >> ry;
        red.push_back(make_pair(ry,rx));
    }
    for(i=0; i<N; i++){
        cin >> bx >> by;
        blue.push_back(make_pair(bx,by));
    }

    //calc
    sort(red.begin(),red.end());
    sort(blue.begin(),blue.end());
    int counta=0;
    for(i=0; i<N; i++){
        bx=blue[i].first;
        by=blue[i].second;
        for(j=red.size()-1; j>=0; j--){
            rx=red[j].second;
            ry=red[j].first;
            if(rx<bx && ry<by){
                counta++;
                red.erase(red.begin()+j);
                break;
            }
        }
    }

    //answer
    cout << counta << endl;
    system("pause");
    return 0;
}