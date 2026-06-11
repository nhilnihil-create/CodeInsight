#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>

struct citys
{
    long city_num;
    long year;
    std::string number;
    citys(long city_num1, long year1, std::string number1){
    city_num=city_num1;
    year=year1;
    number = number1;
  }
  bool operator<( const citys &another ) const {
        return year<another.year;
  }
};

struct num_and_name
{
    long city_num;
    std::string number;
    num_and_name(long city_num1, std::string number1){
    city_num=city_num1;
    number = number1;
  }
  bool operator<( const num_and_name &another ) const {
        return city_num<another.city_num;
  }
};

std::vector<std::vector<citys> > map(100000+1);

int main(){
    long N,M;
    std::cin >> N >> M;
    for(long i=0; i<M; i++){
        long P,Y;
        std::cin >> P >> Y;
        map[P].push_back(citys(i,Y,"T"));
    }

    for(long i=1; i<100000+1; i++){
        std::sort(map[i].begin(),map[i].end());
    }

    for(long i=1; i<100000+1; i++){
        std::string name("000000");
        long P_num=i;
        long count=6-1;
        while(P_num>0){
            name[count]='0'+(P_num%10);
            P_num=P_num/10;
            count-=1;
        }

        for(long j=0; j<map[i].size(); j++){
            std::string Cname("000000");
            long C_num=j+1;
            long countC=6-1;
            while(C_num>0){
                Cname[countC]='0'+(C_num%10);
                C_num=C_num/10;
                countC-=1;
            }
            map[i][j].number = name+Cname;
        }
    }

    std::vector<num_and_name> result;
    for(long i=1; i<100000+1; i++){
        for(long j=0; j<map[i].size(); j++){
            result.push_back(num_and_name(map[i][j].city_num,map[i][j].number));
        }
    }
    std::sort(result.begin(),result.end());
    for(long i=0;i<M; i++){
        std::cout << result[i].number << std::endl;
    }
    return 0;
}