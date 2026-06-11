#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int datanum,x_now,y_now,index_x,index_y,hight_now;
    int i,j,zv_counter=0;
    int tmp_height,height;
    int field[128][8]={{0}};
    int ispeak=1;
    
    cin >> datanum;
    
    for(i=0;i<datanum;i++){
        cin >> field[i][0] >>field[i][1] >> field[i][2];
        if(field[i][2]!=0){
            zv_counter++;
            index_x=field[i][0];
            index_y=field[i][1];
        }
    }
    //
    tmp_height = 0;
    //
    for(j=0;j<10201;j++){
        x_now = j%101;
        y_now = j/101;
        ispeak= 1;

        for(i=0;i<datanum;i++){
            if(field[i][2]!=0){
                height = field[i][2] + abs(field[i][0]-x_now) + abs(field[i][1]-y_now);
                break;
            }
        }
        for(i=0;i<datanum;i++){
            
            tmp_height = field[i][2] + abs(field[i][0]-x_now) + abs(field[i][1]-y_now);
            
            if(field[i][2] != 0 && height != tmp_height){
                ispeak = 0;   
            }else if(zv_counter <= 1){
                x_now=index_x;
                y_now=index_y;
            }
        }
        if(ispeak) break;
    }
    cout <<x_now<<" "<<y_now<<" "<<height<< endl;
    return 0;
}