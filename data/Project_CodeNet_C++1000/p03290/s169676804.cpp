#include<iostream>
using namespace std;

int main(){
    //input
    long long D, G;
    cin >> D >> G;
    long long p[D], c[D];
    long long i;
    for(i=0; i<D; i++){
        cin >> p[i] >> c[i];
    }

    //calc
    long long count, count_min;
    long long score;
    long long bit;
    long long gred;
    count_min=0;
    for(i=0; i<D; i++){
        count_min += p[i];
    }
    for(bit=0; bit<(1<<D)-1; bit++){
        count=0;
        score=0;
        for(i=0; i<D; i++){
            if(bit&(1<<i)){
                count += p[i];
                score += 100*(i+1)*p[i] + c[i];
            }
        }
        for(gred=D-1; gred>=0; gred--){
            if(bit&(1<<gred)){
                continue;
            }
            break;
        }
        for(i=0; i<p[gred]-1; i++){
            if(score>=G){
                break;
            }
            count++;
            score += 100*(gred+1);
        }
        if(score>=G){
            count_min=min(count,count_min);
        }
    }

    //answer
    cout << count_min << endl;
    system("pause");
    return 0;
}