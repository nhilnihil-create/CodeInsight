//問題やり直し
#include <iostream>
#include <string>
using namespace std;

typedef struct{           /* _person がタグ名 */
    int x,y,t;               /* 整数型メンバ age */
} acord_t;

int main(void)
{
  int N;
  cin >> N;
  acord_t point[N];
  for(int i=0; i<N; i++){
    cin >> point[i].t;
    cin >> point[i].x;
    cin >> point[i].y;
  }

  for(int j=0; j<N; j++){
    // cout << "fucnk";
    int x_dis,y_dis,t_dis;
    if(j==0){
      x_dis = point[j].x;
      y_dis = point[j].y;
      t_dis = point[j].t;
    }else{
      x_dis = point[j].x - point[j-1].x;
      y_dis = point[j].y - point[j-1].y;
      t_dis = point[j].t - point[j-1].t;
    }

    int x_front,x_back,y_front,y_back;
    //x_back+y_back=1/2{t_dis-x_dis-y_dis}
    if((t_dis-x_dis-y_dis) %2 != 0){
      cout << "No\n";
      return 0;
    }
    // int x_back_min, y_back_min;
    // if(x_dis>0) x_back_min = 0;
    // else x_back_min = -x_dis;
    // if(y_dis>0) y_back_min = 0;
    // else y_back_min = -y_dis;
    // if(x_back_min+y_back_min > (t_dis-x_dis-y_dis)/2){
    //   cout << "NO\n";
    //   return 0;
    // }
    if(abs(x_dis)+abs(y_dis) > t_dis){
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}
