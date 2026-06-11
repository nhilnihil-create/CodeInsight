#include <bits/stdc++.h>
using namespace std;

int main(){
  using point= pair<int64_t, int64_t>;
  int N,K;
  cin >> N >> K;
  const int Kin= K-2;

  vector<point> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i).first >> data.at(i).second;
  }
  sort(data.begin(), data.end());

  int64_t ans= INT64_MAX;
  for(int j1=0; j1<N; j1++){
    for(int j2=j1+1; j2<N; j2++){
      point p1= data.at(j1);
      point p2= data.at(j2);
      int64_t ymax= max(p1.second, p2.second);
      int64_t ymin= min(p1.second, p2.second);

      if(Kin==0){
        int64_t xmax= max(p1.first, p2.first);
        int64_t xmin= min(p1.first, p2.first);

        ans= min(ans, (xmax- xmin)*(ymax- ymin));
      }
      else{
        vector<int64_t> Xs_in_Yrange;
        for(int i=0; i<N; i++){
          if(i==j1 || i==j2){ continue; }
          else{
            if(ymin <= data.at(i).second && data.at(i).second <= ymax){
              Xs_in_Yrange.emplace_back(data.at(i).first);
            }
          }
        }
        int Nin= Xs_in_Yrange.size();
        if(Nin >= Kin){
          for(int i=0; i+Kin-1 < Nin; i++){
            int64_t xmax= max(Xs_in_Yrange.at(i+Kin-1), max(p1.first, p2.first));
            int64_t xmin= min(Xs_in_Yrange.at(i)      , min(p1.first, p2.first));

            ans= min(ans, (xmax- xmin)*(ymax- ymin));
          }
        }
      }
    }
  }

  cout << ans << endl;
}