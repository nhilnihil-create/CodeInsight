#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
    int h , w ;
    cin >> h >> w;

    string blank ;
    for ( int i = 0; i < w + 2; i++)
    {
     blank +=".";
    }

    string str = blank;

    for (int i = 0; i < h ; i++)
    {
        string s ;
        cin >> s ;
        str += "."+ s + ".";
        //strin =  "."+ s + ".";
        //cout << strin << endl;
    }
    //cout << blank << endl;

     str += blank;
     //cout << str << endl;
    for (int  i = 0; i < h; i++)
    {
        string yokoretu;
        for (int j = 0; j < w; j++)
        {
            if(str.at((w+2)*(i+1) + j+1 )== '#'){
                yokoretu += "#";
            }
            else{
                string what_does_exist ;
                what_does_exist = str.substr((w+2)*(i) + j,3)+
                                str.substr((w+2)*(i+1) + j,1)+str.substr((w+2)*(i+1) + j+2,1)+ 
                                str.substr((w+2)*(i+2) + j,3);
                //cout << "what does exist" <<  what_does_exist << endl;
                int how_many_bomb = 0;
                for (int k = 0; k < 8; k++)
                {
                    if(what_does_exist.at(k) == '#'){
                        how_many_bomb ++;
                    }
                }
                //cout << "how many bomb" << how_many_bomb << endl;
                

                yokoretu += to_string(how_many_bomb);   
            }
        }
        cout << yokoretu << endl;
        
    }
    

}