#include <bits/stdc++.h>
using namespace std;

int main(){
    int d,g;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    for(int i=0; i<d; i++){
        cin >> p.at(i);
        cin >> c.at(i);
    }
    int score = 0;
    int snum = 0;
    int com_snum = INT_MAX;
    for(int i=0; i<(1<<d); i++){
        bitset<11> bit(i);
        //cout << bit << endl;
    
        for(int j=0; j<d; j++){
            if(bit.test(j)){
                score += c.at(j);
                score += p.at(j) * 100*(j+1);
                snum += p.at(j);
            }
        }
        //cout << score << endl;
        //cout << snum << endl;
        if(score >= g){
            //cout << snum << endl;
        }
        else{
            for(int k=d-1; k>=0; k--){
                if(!bit.test(k) && score < g){
                    for(int l=1; l<=p.at(k); l++){
                        if(score+l*(k+1)*100 >= g){
                            snum += l;
                            score += l*(k+1)*100;
                            //cout << score << endl;
                            break;
                        }
                        if(l==p.at(k)){
                            snum += p.at(k)-1;
                            score += (p.at(k)-1)*(k+1)*100;
                        }
                    }
                }
            }
        }
        //cout << score << endl;
        //cout << snum << endl;
        if(com_snum > snum && score >= g){
            com_snum = snum;
        }
        score = 0;
        snum = 0;
    }
    //cout << "最小回数=" << com_snum << endl;
    cout << com_snum << endl;
}