#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    string S;
    cin>>N>>S;
    int counttt=0;
    for(int i=1;i<N;i++){
        vector<int>AAA(26,0);
        string a=S.substr(0,i);
        string b=S.substr(i,N-i);
        int count=0;
        for(int j=0;j<i;j++){
            for(int k=0;k<N-i;k++){
                if(a.at(j)==b.at(k)){
                    if(a.at(j)=='a'){
                        AAA.at(0)++;
                    }
                 else   if(a.at(j)=='b'){
                        AAA.at(1)++;
                    }
                  else  if(a.at(j)=='c'){
                        AAA.at(2)++;
                    }
                  else  if(a.at(j)=='d'){
                        AAA.at(3)++;
                    }
                  else  if(a.at(j)=='e'){
                        AAA.at(4)++;
                    }
                    if(a.at(j)=='f'){
                        AAA.at(5)++;
                    }
                  else  if(a.at(j)=='g'){
                        AAA.at(6)++;
                    }
                 else   if(a.at(j)=='h'){
                        AAA.at(7)++;
                    }
                  else  if(a.at(j)=='i'){
                        AAA.at(8)++;
                    }
                  else  if(a.at(j)=='j'){
                        AAA.at(9)++;
                    }
                 else   if(a.at(j)=='k'){
                        AAA.at(10)++;
                    }
                  else  if(a.at(j)=='n'){
                        AAA.at(11)++;
                    }
                 else   if(a.at(j)=='m'){
                        AAA.at(12)++;
                    }
                  else  if(a.at(j)=='l'){
                        AAA.at(13)++;
                    }
                  else  if(a.at(j)=='o'){
                        AAA.at(14)++;
                    }
                  else  if(a.at(j)=='p'){
                        AAA.at(15)++;
                    }
                  else  if(a.at(j)=='q'){
                        AAA.at(16)++;
                    }
                  else  if(a.at(j)=='r'){
                        AAA.at(17)++;
                    }
                    if(a.at(j)=='s'){
                        AAA.at(18)++;
                    }
                  else  if(a.at(j)=='t'){
                        AAA.at(19)++;
                    }
                  else  if(a.at(j)=='u'){
                        AAA.at(20)++;
                    }
                   else if(a.at(j)=='v'){
                        AAA.at(21)++;
                    }
                   else if(a.at(j)=='w'){
                        AAA.at(22)++;
                    }
                   else if(a.at(j)=='x'){
                        AAA.at(23)++;
                    }
                   else if(a.at(j)=='y'){
                        AAA.at(24)++;
                    }
                   else if(a.at(j)=='z'){
                        AAA.at(25)++;
                    }
                }
            }
        }
        for(int t=0;t<26;t++){
            if(AAA.at(t)>=1){
                count++;
            }
        }
        counttt=max(count,counttt);
    }
    cout<<counttt<<endl;
}